import React from 'react'

function SearchBar({ onSearch,
    onQueryChange,
    searchQuery}) {
  return (
    <div
    className='flex items-center justify-between w-full px-4 py-2 '
    >
        <input
            className='w-full px-2 py-1  text-gray-700 placeholder-gray-500 border border-gray-300 rounded-md focus:outline-none '
            type="text"
            placeholder="Search"
            value={searchQuery}
            onChange={(e) => onQueryChange(e.target.value)}
        />
        {/* Icon buttno */}
        <button className='flex items-center justify-center w-12 h-12 ml-2 text-gray-500 bg-gray-100 rounded-full hover:text-gray-700 hover:bg-gray-200 focus:outline-none '>
            <svg className='w-6 h-6' fill='none' stroke='currentColor' viewBox='0 0 24 24' xmlns='http://www.w3.org/2000/svg'>
                <path strokeLinecap='round' strokeLinejoin='round' strokeWidth='2' d='M15 11a4 4 0 11-8 0 4 4 0 018 0z'></path>
                <path strokeLinecap='round' strokeLinejoin='round' strokeWidth='2' d='M21 21l-4.35-4.35'></path>
            </svg>
        </button>

    </div>
  )
}

export default SearchBar