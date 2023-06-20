
import React from 'react'
import { useNavigate } from 'react-router-dom';
import { Lanugeages, templates } from '../public/templates';
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
        browser.storage.local.set({ localTemplates: [...localTemplates, template] });
        navigate("/");
    }

  return (
    <div>
        <NHeader goBackIcon></NHeader>
        <form
        className='flex flex-col items-center justify-center w-full px-4 py-2'
        onSubmit={(e) => {
            e.preventDefault();
            onAddTemplate(template);
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
            type="text"
            placeholder="Code"
            value={template.src}
            onChange={(e) => setTemplate({ ...template, src: e.target.value })}
            />
            <button
            className='px-4 py-2 mb-2 text-white bg-blue-500 rounded-md'
            type="submit"
            >
                Add Template
            </button>
        </form>

            

    </div>
  )
}

export default AddTemplate