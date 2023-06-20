import "react-tooltip/dist/react-tooltip.css";
import "./style.css";
import Root from "./Root.jsx";
import * as React from "react";
import * as ReactDOM from "react-dom/client";
import { createMemoryRouter ,RouterProvider} from "react-router-dom";
import AddTemplate from "./AddTemplate.jsx";
const router = createMemoryRouter([
  {
    path: "/",
    element: <Root />,
  },
  {
    path: "/add-template",
    element: <AddTemplate />,
  }
]);

ReactDOM.createRoot(document.getElementById("react-target")).render(
  <React.StrictMode>

    <RouterProvider 
    router={router} />
  </React.StrictMode>
);