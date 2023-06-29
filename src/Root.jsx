import React from "react";
import { render } from "react-dom";
import NHeader from "./NHeader.jsx";
import SearchBar from "./SearchBar.jsx";
import ShowResults from "./ShowResults.jsx";
import Footer from "./Footer.jsx";
import Options from "./Options.jsx";
import { loadTemplates } from "../helper/index.js";
// available code templates
const browser = window.browser || window.chrome;
export default function Root() {
  const [searchQuery, setSearchQuery] = React.useState("");
  const [language, setLanguage] = React.useState("All");
  const [localOnly, setLocalOnly] = React.useState(false);
  const [searchResults, setSearchResults] = React.useState([]);
  const [templates, setTemplates] = React.useState([]);
  React.useEffect(() => {
    const getTemplates = async () => {
      loadTemplates().then(async (data) => {
        const officialTemplates = data.sort((a, b) => {
          if (a.name < b.name) return -1;
          return 1;
        });
        const localTemplates =
          (await browser.storage.local.get(["localTemplates"]))
            .localTemplates || [];
        console.log("lolcal", localTemplates,officialTemplates);
        setTemplates([...officialTemplates, ...localTemplates]);
      });
    };
    const getUserPreference = async () => {
      browser.storage.sync.get("language", (data) => {
        setLanguage(data.language);
      });
      browser.storage.sync.get("localOnly", (data) => {
        setLocalOnly(data.localOnly);
      });
    };
    getTemplates();
    getUserPreference();
  }, []);

  React.useEffect(() => {
    filter(searchQuery, language, localOnly); // take care of syncing search results with state
  }, [templates, searchQuery, language, localOnly]);

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
          lang.toLowerCase().includes(q.toLowerCase()))
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
  const onDeleteTemplate = (name, lang, authr) => {
    const modified = templates.filter(
      (t) => t.name !== name || t.language !== lang || t.author !== authr
    );
    browser.storage.local.set({ localTemplates: modified.filter((t) => t.local) });
    setTemplates([...modified]);
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
