const browser = window.browser || window.chrome;
export async function loadTemplates() {
  return fetch(BASE_URL + "templates.json")
    .then((res) => res.json())
    .then((res) => {
      browser.storage.local.set({ templates: res });
      return res;
    })
    .catch((err) => {
      console.log("error while loading definations using old one", err);
      return browser.storage.local.get(["templates"]).then((res) => {
        return res.templates;
      });
    });
}
export const BadgeColors = {
  Cpp: "bg-blue-500",
  Python: "bg-yellow-500",
  Java: "bg-red-500",
  JavaScript: "bg-yellow-500",
  C: "bg-blue-500",
};

export const Languages = [
    "C",
    "Cpp",
    "Python",
    "Java",
    "JavaScript",
    ].sort((a, b) => {
    if (a < b) return -1;  
    return 1;
});
