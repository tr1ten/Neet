import React from 'react'

export default function NHeader() {
  return (
    <div
        className='flex items-center justify-between w-full px-4 py-2 bg-white border-b border-gray-200'
    >
       <div
       className='w-full'
       >
        <img
        width='100'
         href='logo.png' alt='logo' />
       </div>
        {/* Github icon with link */}
        <a href="#" target="_blank" rel="noopener noreferrer">
            <img src="https://img.icons8.com/ios-filled/50/000000/github.png" alt="Github" />
        </a>
    </div>
  )
}
