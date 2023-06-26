
import React from 'react'
import { useNavigate } from 'react-router-dom';
import { Lanugeages, templates } from '../helper';
import NHeader from './NHeader.jsx';

// this allows user to add custom templates which is stored in browser storage
// this component present a form to add custom template
// name, author, language, code
// storage not working :()
const browser = window.browser || window.chrome;
function AddTemplate() {
    const [template, setTemplate] = React.useState({
        name: "",
        language: "",
        author: "local",
        src: "",
        local: true,
        published: new Date().toISOString().slice(0, 10),
    });
    const navigate = useNavigate();
    const onAddTemplate = async () => {
        const localTemplates = (await browser.storage.local.get(["localTemplates"])).localTemplates || [];
        // check if template already exists
        const exists = localTemplates.find((t) => t.name == template.name && t.language == template.language && t.author == template.author);
        if (!exists) {
            // convert src code to blob url
            const blob = new Blob([template.src], { type: "text/plain" });
            const src = URL.createObjectURL(blob);
            const temp = { ...template, src };
            browser.storage.local.set({ localTemplates: [...localTemplates, temp] });

        }
        navigate("/");
    }

  return (
    <div>
        <NHeader goBackIcon></NHeader>
        <h2
        className='w-full px-4 py-2 text-2xl font-bold text-center text-gray-700'
        >
            New Local Template
        </h2>
        <form
        className='flex flex-col items-center justify-center w-full px-4 py-2'
        onSubmit={(e) => {
            e.preventDefault();
            onAddTemplate();
        }}
        >
            <input
            className='w-full px-4 py-2 mb-2 border border-gray-200 rounded-md'
            type="text"
            placeholder="Name"
            value={template.name}
            onChange={(e) => setTemplate({ ...template, name: e.target.value })}
            />
            <input
            className='w-full px-4 py-2 mb-2 border border-gray-200 rounded-md'
            type="text"
            placeholder="Author"
            value={template.author}
            onChange={(e) => setTemplate({ ...template, author: e.target.value })}
            />
            <select
            className='w-full px-4 py-2 mb-2 border border-gray-200 rounded-md'
            value={template.language}
            onChange={(e) => setTemplate({ ...template, language: e.target.value })}
            >
                <option value="" disabled> 
                    Select Language
                </option>
                {Lanugeages.map((language) => (
                    <option key={language} value={language}>
                        {language}
                    </option>
                ))}
            </select>
            <textarea
            className='w-full px-4 py-2 mb-2 border border-gray-200 rounded-md'
            rows={10}

            type="text"

            placeholder="Code"
            value={template.src}
            onChange={(e) => setTemplate({ ...template, src: e.target.value })}
            />
            <button
            disabled={!template.src || !template.language || !template.name || !template.author}
            className='px-4 py-2 mb-2 text-white bg-blue-500 rounded-md disabled:bg-gray-400'
            type="submit"
            >
                Add Template
            </button>
        </form>

            

    </div>
  )
}

export default AddTemplate