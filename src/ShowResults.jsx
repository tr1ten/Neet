import React from 'react'
import Template from './Template.jsx'

function ShowResults({results}) {
    if(results.length === 0) {
        return <div className='flex items-center justify-center w-full h-full text-2xl text-gray-500'>No results found</div>
    }
  return (
    <div className='flex flex-col items-center justify-center '>
        {results.map((result,id) => <Template key={id} {...result} />)}
    </div>
  )
}

export default ShowResults