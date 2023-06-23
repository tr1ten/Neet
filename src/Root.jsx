import React from "react";
import { render } from "react-dom";
import NHeader from "./NHeader.jsx";
import SearchBar from "./SearchBar.jsx";
import ShowResults from "./ShowResults.jsx";
import Footer from "./Footer.jsx";
import { templates as Data } from "../public/templates/index.js";
import Options from "./Options.jsx";
// available code templates
export default function Root() {
  const browser = window.browser || window.chrome;
  const [searchQuery, setSearchQuery] = React.useState("");
  const [language, setLanguage] = React.useState("All");
  const [localOnly, setLocalOnly] = React.useState(false);
  const [searchResults, setSearchResults] = React.useState(Data);
  const [templates, setTemplates] = React.useState(Data);
  // todo fix filtering logic, so many bugs there :(
  React.useEffect(() => {
    const getLocalTemplates = async () => {
      const localTemplates =
        (await browser.storage.local.get(["localTemplates"])).localTemplates ||
        [];
      setTemplates([...Data, ...localTemplates]);
    };
    const getUserPreference = async () => {
      browser.storage.sync.get("language", (data) => {
        setLanguage(data.language);
      });
      browser.storage.sync.get("localOnly", (data) => {
        setLocalOnly(data.localOnly);
      });
    };
    getLocalTemplates();
    getUserPreference();
  }, []);

  React.useEffect(() => {
    filter(searchQuery, language, localOnly); // take care of syncing search results with state
  }, [templates,searchQuery, language, localOnly]);

  const filter = (q, preferred_lang, isLocalOnly) => {
    const results = templates.filter((template) => {
      const { name, author, language: lang, local } = template;
      return (
        (!isLocalOnly || local) &&
        (!preferred_lang ||
          preferred_lang.toLowerCase() == "all" ||
          preferred_lang.toLowerCase().includes(lang.toLowerCase())) &&
        (!q ||
          name.toLowerCase().includes(q.toLowerCase()) ||
          author.toLowerCase().includes(q.toLowerCase()) ||
          language.toLowerCase().includes(q.toLowerCase()))
      );
    });
    setSearchResults(results);
  };
  const setKey = (key, val) => {
    return browser.storage.sync.set({ [key]: val });
  };
  const onLanguageChange = (value) => {
    setLanguage(value);
    setKey("language", value);
  };
  const onLocalChange = (value) => {
    // local template has local = true
    setLocalOnly(value);
    setKey("localOnly", value);
  };
  const onQueryChange = (value) => {
    setSearchQuery(value);
  };
  const onDeleteTemplate = (name,lang,authr) => {
    const localTemplates = templates.filter((t) => t.local && (t.name !== name  || t.language !== lang || t.author !== authr));
    browser.storage.local.set({ localTemplates });
    setTemplates([...Data, ...localTemplates]);
  };
  return (
    <main>
      <NHeader></NHeader>
      <SearchBar
        onSearch={filter}
        onQueryChange={onQueryChange}
        searchQuery={searchQuery}
      ></SearchBar>
      <Options
        language={language}
        localOnly={localOnly}
        onLanguageChange={onLanguageChange}
        onLocalChange={onLocalChange}
      ></Options>
      <ShowResults
        onDelete={onDeleteTemplate}
        results={searchResults}
      ></ShowResults>
      <Footer></Footer>
    </main>
  );
}
