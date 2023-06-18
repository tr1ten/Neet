import React from 'react'

export default function NHeader() {
  return (
    <div
        className='flex items-center justify-between w-full px-4 py-2 
         border-b border-gray-200'
    >
       <div
       className='w-full'
       >
        {/* Logo png img */}
        <img 
        className='w-16 m-auto'
        src="logo.png" alt="logo" />
       </div>
        {/* Github icon with link */}
        <a href="https://github.com/tr1ten/Neet" target="_blank" rel="noopener noreferrer">
            <img 
            className='w-6 '
            src="https://img.icons8.com/ios-filled/50/000000/github.png" alt="Github" />
        </a>
    </div>
  )
}
