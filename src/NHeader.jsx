import React from 'react'

export default function NHeader() {
  return (
    <div
        // leetcode style header
        className='flex items-center justify-between w-full px-4 py-2 bg-white border-b border-gray-200'
    >
       <div
       className='w-full'
       >
       <h1
            className='text-4xl font-bold text-center text-gray-800 '
        >Neet</h1>
       </div>
        {/* Github icon with link */}
        <a href="#" target="_blank" rel="noopener noreferrer">
            <img src="https://img.icons8.com/ios-filled/50/000000/github.png" alt="Github" />
        </a>
    </div>
  )
}
