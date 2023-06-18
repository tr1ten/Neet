import 'react-tooltip/dist/react-tooltip.css';
import './style.css';
import React from "react";
import { render } from "react-dom";
import NHeader from "./NHeader.jsx";
import SearchBar from "./SearchBar.jsx";
import ShowResults from "./ShowResults.jsx";
import Footer from "./Footer.jsx";
import {templates} from "../public/templates/index.js";
import Options from './Options.jsx';
// available code templates

function Popup() {
  const [searchResults, setSearchResults] = React.useState(templates);
  const [searchQuery, setSearchQuery] = React.useState("");
  const [language, setLanguage] = React.useState("All");
  const [localOnly, setLocalOnly] = React.useState(false);
  const filter = (q) => {
      const results = templates.filter((template) => {
          const { name, author, language } = template;
          return (
              name.toLowerCase().includes(q) ||
              author.toLowerCase().includes(q) ||
              language.toLowerCase().includes(q)
          );
      });
      setSearchResults(results);
  }
  const onLanguageChange = (value) => {
      setLanguage(value);
      if (value === "All") setSearchResults(templates);
      else {
          const results = templates.filter((template) => {
              const { language } = template;
              return language.toLowerCase() == (value.toLowerCase());
          });
          setSearchResults(results);
      }
  };

  const onQueryChange = (value) => {
      setSearchQuery(value);
      if (value) filter(value);
      else setSearchResults(templates);
  }
  return <main>
    <NHeader></NHeader>
    <SearchBar onSearch={filter} 
    onQueryChange={onQueryChange}
    searchQuery={searchQuery}
    ></SearchBar>
    <Options language={language} localOnly={localOnly} onLanguageChange={onLanguageChange} onLocalChange={setLocalOnly}></Options>
    <ShowResults results={searchResults}></ShowResults>

  </main>
}

render(<Popup />, document.getElementById("react-target"));