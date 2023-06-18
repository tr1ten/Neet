import React from "react";
import { Tooltip } from 'react-tooltip';
import {BadgeColors} from '../public/templates/index.js'
// Card
// Name, Author, Language, Published

function Template({ author, language, name, published, src }) {
  const [copyStatus, setCopyStatus] = React.useState(false);
  const onCopy = () => {
    fetch(src).then((res) => res.text()).then((text) => {
      navigator.clipboard.writeText(text);
    });
    setCopyStatus(true);
    setTimeout(() => {
      setCopyStatus(false);
    }, 1000);
  }
  return (
    <div
      className="
      flex flex-row justify-between w-full  border  p-2
    "
    >
      <div className="flex flex-col">
        <h2 className="font-semibold text-lg">{name} </h2>
        <div className="text-xs text-gray-500">
          <span className=" text-gray-500 italic mx-2">{author} ({published})</span>
          {/* Lanugeage badge */}
          <span
            className={`px-2 py-1 text-xs font-semibold ${BadgeColors[language]} text-white rounded-full `}
          >
            {language}
            
          </span>
        </div>
      </div>
      {/* Copy and view icon button */}
      <div
      className="flex flex-row gap-2"
      >
        {/* copy paste icon */}
        <button 
        onClick={onCopy}
        data-tooltip-id="cpt"
        data-tooltip-content={copyStatus ? "Copied" : "Copy"}
        className="flex items-center justify-center  ml-2 text-gray-500 ">
        <Tooltip id="cpt" />
          <svg
            fill="#000000"
            height="24"
            viewBox="0 0 1920 1920"
            xmlns="http://www.w3.org/2000/svg"
          >
            <path
              d="M0 1919.887h1467.88V452.008H0v1467.88ZM1354.965 564.922v1242.051H112.914V564.922h1242.051ZM1920 0v1467.992h-338.741v-113.027h225.827V112.914H565.035V338.74H452.008V0H1920ZM338.741 1016.93h790.397V904.016H338.74v112.914Zm0 451.062h790.397v-113.027H338.74v113.027Zm0-225.588h564.57v-112.913H338.74v112.913Z"
              fillRule="evenodd"
            />
          </svg>
        </button>
        {/* view icon */}
        <button 
        onClick={()=>{
          window.open(src)
        }}
        data-tooltip-id="vwt"
        data-tooltip-content="View"
        className="flex items-center justify-center  ml-2 ">
          <Tooltip id="vwt" />
          <svg
          height={24}
            viewBox="0 0 24 24"
            fill="none"
            xmlns="http://www.w3.org/2000/svg"
          >
            <path
              d="M15 12C15 13.6569 13.6569 15 12 15C10.3431 15 9 13.6569 9 12C9 10.3431 10.3431 9 12 9C13.6569 9 15 10.3431 15 12Z"
              stroke="#323232"
              strokeWidth="2"
            />
            <path
              d="M6.94975 7.05025C9.68342 4.31658 14.1156 4.31658 16.8492 7.05025L18.9706 9.17157C20.3039 10.5049 20.9706 11.1716 20.9706 12C20.9706 12.8284 20.3039 13.4951 18.9706 14.8284L16.8492 16.9497C14.1156 19.6834 9.68342 19.6834 6.94975 16.9497L4.82843 14.8284C3.49509 13.4951 2.82843 12.8284 2.82843 12C2.82843 11.1716 3.49509 10.5049 4.82843 9.17157L6.94975 7.05025Z"
              stroke="#323232"
              strokeWidth="2"
              strokeLinejoin="round"
            />
          </svg>
        </button>
      </div>
    </div>
  );
}

export default Template;
