import React from 'react'
import Template from './Template.jsx'

function ShowResults({results,onDelete}) {
    if(results.length === 0) {
        return <div className='flex items-center justify-center h-3/5 text-2xl text-gray-500'>No results found!</div>
    }
  return (
    <div className='show-res-cont'>
        <div className='flex flex-col show-res'>
        {results.map((result,id) => <Template key={id} {...result} onDelete={onDelete} />)}
    </div>
    </div>
  )
}

export default ShowResults