import React from "react";
import { Tooltip } from "react-tooltip";
import { BadgeColors } from "../helper/index.js";
// Card
// Name, Author, Language, Published

function Template({ author, language, name, published, src,local, onDelete }) {
  const [copyStatus, setCopyStatus] = React.useState(false);
  const url = src;
  const onCopy = () => {
    fetch(url)
      .then((res) => res.text())
      .then((text) => {
        navigator.clipboard.writeText(text);
        setCopyStatus(true);
    setTimeout(() => {
      setCopyStatus(false);
    }, 1000);
      });
    
  };
  return (
    <div
      className="
      flex flex-row justify-between w-full  border  p-2
    "
    >
      <div className="flex flex-col">
        <h2 className="font-semibold text-sm">{name} </h2>
        <div className="text-xs text-gray-500 my-1 flex gap-2">
          <span className=" text-gray-500 italic">
            {author} ({published})
          </span>
          {/* Lanugeage badge */}
          <span
            className={`px-2 py-1 text-xs ${BadgeColors[language]} text-white rounded-full `}
          >
            {language}
          </span>
        </div>
      </div>
      {/* Copy and view icon button */}
      <div className="flex flex-row gap-2">
        {/* Delete icon */}
       {
          local && (
            <button
          onClick={()=> onDelete(name,language,author)}
          data-tooltip-id="del"
          data-tooltip-content="Delete"
          className="flex items-center justify-center  ml-2 text-gray-500 "
        >
          <Tooltip id="del" />
          <svg
            width="24px"
            viewBox="0 0 1024 1024"
            className="icon"
            version="1.1"
            xmlns="http://www.w3.org/2000/svg"
          >
            <path
              d="M905.92 237.76a32 32 0 0 0-52.48 36.48A416 416 0 1 1 96 512a418.56 418.56 0 0 1 297.28-398.72 32 32 0 1 0-18.24-61.44A480 480 0 1 0 992 512a477.12 477.12 0 0 0-86.08-274.24z"
              fill="red"
            />
            <path
              d="M630.72 113.28A413.76 413.76 0 0 1 768 185.28a32 32 0 0 0 39.68-50.24 476.8 476.8 0 0 0-160-83.2 32 32 0 0 0-18.24 61.44zM489.28 86.72a36.8 36.8 0 0 0 10.56 6.72 30.08 30.08 0 0 0 24.32 0 37.12 37.12 0 0 0 10.56-6.72A32 32 0 0 0 544 64a33.6 33.6 0 0 0-9.28-22.72A32 32 0 0 0 505.6 32a20.8 20.8 0 0 0-5.76 1.92 23.68 23.68 0 0 0-5.76 2.88l-4.8 3.84a32 32 0 0 0-6.72 10.56A32 32 0 0 0 480 64a32 32 0 0 0 2.56 12.16 37.12 37.12 0 0 0 6.72 10.56zM726.72 297.28a32 32 0 0 0-45.12 0l-169.6 169.6-169.28-169.6A32 32 0 0 0 297.6 342.4l169.28 169.6-169.6 169.28a32 32 0 1 0 45.12 45.12l169.6-169.28 169.28 169.28a32 32 0 0 0 45.12-45.12L557.12 512l169.28-169.28a32 32 0 0 0 0.32-45.44z"
              fill="red"
            />
          </svg>
        </button>
          )
       }
        {/* copy paste icon */}
        <button
          onClick={onCopy}
          data-tooltip-id="cpt"
          data-tooltip-content={copyStatus ? "Copied" : "Copy"}
          className="flex items-center justify-center  ml-2 text-gray-500 "
        >
          <Tooltip id="cpt" />
          <svg
            fill="#000000"
            height="16"
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
          onClick={() => {
            window.open(url);
          }}
          data-tooltip-id="vwt"
          data-tooltip-content="View"
          className="flex items-center justify-center  ml-2 "
        >
          <Tooltip id="vwt" />
          <svg
            height={16}
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
