import React from 'react'
import { useNavigate } from 'react-router-dom'

export default function NHeader({goBackIcon}) {
    const navigate = useNavigate();
    const onGoBack = () => {
        navigate(-1);
    }
    const GoBackIcon = () => {
        return (
            <svg
            onClick={onGoBack}
            className='w-6 cursor-pointer'
            xmlns="http://www.w3.org/2000/svg" viewBox="0 0 24 24" fill="none" stroke="#000000" strokeWidth="2" strokeLinecap="round" strokeLinejoin="round">
                <polyline points="15 18 9 12 15 6"></polyline>
            </svg>
        )
    }
  return (
    <div
        className='flex items-center justify-between w-full px-4 py-2 
         border-b border-gray-200'
    >
       {
            goBackIcon && <GoBackIcon />
       }
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
