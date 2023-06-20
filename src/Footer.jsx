import React from 'react'
import { Link } from 'react-router-dom'

function Footer() {
  return (
    <div
    className='flex items-center justify-between w-full px-4'
    >
    <Link
    to='/add-template'
    >
        Custom Template
    </Link>
    <a
    >
      Bug Report
    </a>
    </div>
  )
}

export default Footer