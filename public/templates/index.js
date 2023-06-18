export const templates = [
  {
    name: "Binary Search",
    author: "tr1ten",
    language: "Python",
    published: "2021-01-01",
    src: "./templates/binary_search.py",
  },
  {
    name: "DSU",
    author: "tr1ten",
    language: "Python",
    published: "2021-01-01",
    src: "./templates/dsu.py",
  },
  {
    name: "Fenwick Tree",
    author: "tr1ten",
    language: "Python",
    published: "2021-01-01",
    src: "./templates/fenwick_tree.py",
  },
  {
    name: "Lowest Common Ancestor (Binary Lifting)",
    author: "tr1ten",
    language: "Cpp",
    published: "2021-01-01",
    src: "./templates/lca.cpp",
  },
  {
    name: "DSU",
    author: "tr1ten",
    language: "Cpp",
    published: "2021-01-01",
    src: "./templates/dsu.cpp",
  },
  {
    name: "Fenwick Tree",
    author: "tr1ten",
    language: "Cpp",
    published: "2021-01-01",
    src: "./templates/fenwick_tree.cpp",
  },
  {
    name: "Sieves Factorization",
    author: "tr1ten",
    language: "Python",
    published: "2021-01-01",
    src: "./templates/sieves_factorization.py",
  },
  {
    name:"Union Find",
    author: "tr1ten",
    language: "Java",
    published: "2021-01-01",
    src: "./templates/Union_Find.java",
  },
  {
    name:"Segment Tree (Generic)",
    author: "tr1ten",
    language: "Python",
    published: "2021-01-01",
    src: "./templates/segment_tree.py",
  },
  
].sort((a, b) => {
    if (a.name < b.name) return -1;
    return 1;
});
export const BadgeColors = {
  Cpp: "bg-blue-500",
  Python: "bg-yellow-500",
  Java: "bg-red-500",
  JavaScript: "bg-yellow-500",
  C: "bg-blue-500",
};
