import 'react-tooltip/dist/react-tooltip.css';
import './style.css';
import React from "react";
import { render } from "react-dom";
import NHeader from "./NHeader.jsx";
import SearchBar from "./SearchBar.jsx";
import ShowResults from "./ShowResults.jsx";
import Footer from "./Footer.jsx";
import {templates} from "../public/templates/index.js";
// available code templates

function Popup() {
  const [searchResults, setSearchResults] = React.useState(templates);
  const [searchQuery, setSearchQuery] = React.useState("");
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
    <ShowResults results={searchResults}></ShowResults>

  </main>
}

render(<Popup />, document.getElementById("react-target"));