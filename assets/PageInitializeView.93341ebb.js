import{u as o,e as s,o as r,c,a as l,f as m,b as u}from"./index.83bf15e3.js";const p={class:"container q-pa-md text-center"},_=u("h4",null,"Initialize",-1),y={__name:"PageInitializeView",setup(d){const n=o(),e=s();function a(){e.notify({type:"info",message:"Initializing..."}),new Promise(i=>{(async function(){n.initialize(),i()})()}).then(()=>{e.notify({type:"positive",message:"Initialized"})})}return(i,t)=>(r(),c("div",p,[_,l(m,{color:"primary",label:"Initialize Core",onClick:t[0]||(t[0]=f=>a())})]))}};export{y as default};
