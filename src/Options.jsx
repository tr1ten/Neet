import React from "react";
import { Languages } from "../helper/index";
// lanuguage prefernce
// local ony or not
function Options({ language, localOnly, onLanguageChange, onLocalChange }) {
  return (
    <div className="flex justify-between items-center mx-3">
      <select
        value={language}
        onChange={(e) => onLanguageChange(e.target.value)}
        className="mb-2 px-4 py-2 text-gray-700 placeholder-gray-500 border border-gray-300 rounded-md focus:outline-none"
      >
        <option value="All">All</option>
        {Languages.map((language) => (
          <option key={language} value={language}>
            {language}
          </option>
        ))}
      </select>
      <div>
        <label
            className="mr-2 text-gray-700"
         htmlFor="local">Local Only</label>
        <input
          type="checkbox"
          checked={localOnly}
          onChange={(e) => onLocalChange(e.target.checked)}
        />
      </div>
    </div>
  );
}

export default Options;
