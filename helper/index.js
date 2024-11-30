      const browser = window.browser || window.chrome;
// cache response in local storage
export function loadTemplatesFromStorage() {
  return browser.storage.local.get(["templates"])?.then((res) => {
    return res.templates;
  });
}
export async function loadTemplates() {
  console.log("loading templates from source...");
  return fetch(BASE_URL + "templates.json" + "/raw?ref=master")
    .then((res) => res.json())
    .then(async (res) => {
      console.log("templates loaded ",res);
      // change src: fetch code from github api then convert to blob url 
      res = await Promise.all(res.map(async (template) => {
        const code = await fetch(BASE_URL + template.src + "/raw?ref=master").then((res) => res.text());
        console.log("code loaded for ", template.src);
        const blob = new Blob([code], { type: "text/plain" });
        const src = URL.createObjectURL(blob);
        return { ...template, src };
      }));
      // store in sorted order of name
      res = res.sort((a, b) => {
        if (a.name < b.name) return -1;
        return 1;
      });
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

export const Lanugeages = [
    "C",
    "Cpp",
    "Python",
    "Java",
    "JavaScript",
    ].sort((a, b) => {
    if (a < b) return -1;  
    return 1;
});
