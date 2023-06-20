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
  const [searchResults, setSearchResults] = React.useState(Data);
  const [searchQuery, setSearchQuery] = React.useState("");
  const [language, setLanguage] = React.useState("All");
  const [localOnly, setLocalOnly] = React.useState(false);
  const [templates, setTemplates] = React.useState(Data);
  React.useEffect(() => {
        const getLocalTemplates = async () => {
            const localTemplates = (await browser.storage.local.get(["localTemplates"])).localTemplates || [];
            console.log("localTemplates", localTemplates);
            setTemplates([...Data, ...localTemplates]);
            setSearchResults([...Data, ...localTemplates]);
          }
        getLocalTemplates();
    },[]);

  const filter = (q) => {
    const results = templates.filter((template) => {
      const { name, author, language,local } = template;
      return local==localOnly && (
        name.toLowerCase().includes(q.toLowerCase()) ||
        author.toLowerCase().includes(q.toLowerCase()) ||
        language.toLowerCase().includes(q.toLowerCase())
      );
    });
    setSearchResults(results);
  };
  const onLanguageChange = (value) => {
    setLanguage(value);
    if (value === "All") setSearchResults(templates);
    else {
      const results = templates.filter((template) => {
        const { language } = template;
        return language.toLowerCase() == value.toLowerCase();
      });
      setSearchResults(results);
    }
  };
  const onLocalChange = (value) => {
      // local template hash local = true
    setLocalOnly(value);
    if (value) {
      const results = templates.filter((template) => {
        const { local } = template;
        return local;
      });
      setSearchResults(results);
    }
    else{
        setSearchResults(templates);
    }
  }
  const onQueryChange = (value) => {
    setSearchQuery(value);
    if (value || localOnly) filter(value);
    else setSearchResults(templates);
  };
  const onDeleteTemplate = (name) => {
      const localTemplates = templates.filter((t) => t.local && t.name !== name);
      browser.storage.local.set({ localTemplates });
      setTemplates([...Data, ...localTemplates]);
      if(!localOnly) filter(searchQuery);
      else setSearchResults(localTemplates);
  }
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
      <ShowResults onDelete={onDeleteTemplate} results={searchResults}></ShowResults>
      <Footer></Footer>
    </main>
  );
}
