import{u as g,e as S,r,o as d,c as m,g as R,a as l,w as _,b as t,h as p,f as n,Q as x}from"./index.83bf15e3.js";import{Q as b}from"./QForm.719d401c.js";const Q={class:"container q-pa-md text-center"},q=t("h4",null,"Shared Data",-1),z={key:0},W=t("p",{class:"text-bold"},"Write Value",-1),w=t("br",null,null,-1),D=t("br",null,null,-1),k=t("br",null,null,-1),B=t("br",null,null,-1),K=t("p",{class:"text-bold"},"Read Value",-1),P={key:1},N={__name:"PageSharedDataView",setup(I){const i=g(),c=S(),s=r(null),o=r(null),u=r(null);function f(){const y=i.module.SharedData.shared().getString("sample",s.value);c.notify({type:"positive",message:"Value: "+y})}function h(){i.module.SharedData.shared().setString("sample",o.value,u.value),c.notify({type:"positive",message:"Data wrote"})}function V(){s.value=null}function v(){o.value=null,u.value=null}return(y,a)=>(d(),m("div",Q,[q,R(i).module.ApplicationCore.shared().isInitialized()?(d(),m("div",z,[W,l(b,{onSubmit:h,onReset:v,class:"q-gutter-md"},{default:_(()=>[l(p,{rounded:"",outlined:"",type:"text",modelValue:o.value,"onUpdate:modelValue":a[0]||(a[0]=e=>o.value=e),label:"Key","lazy-rules":"",rules:[e=>e&&e.length>0||"Please type something"]},null,8,["modelValue","rules"]),l(p,{rounded:"",outlined:"",type:"text",modelValue:u.value,"onUpdate:modelValue":a[1]||(a[1]=e=>u.value=e),label:"Value","lazy-rules":"",rules:[e=>e&&e.length>0||"Please type something"]},null,8,["modelValue","rules"]),t("div",null,[l(n,{label:"Submit",type:"submit",color:"primary"}),l(n,{label:"Reset",type:"reset",color:"primary",flat:"",class:"q-ml-sm"})])]),_:1}),w,D,l(x),k,B,K,l(b,{onSubmit:f,onReset:V,class:"q-gutter-md"},{default:_(()=>[l(p,{rounded:"",outlined:"",type:"text",modelValue:s.value,"onUpdate:modelValue":a[2]||(a[2]=e=>s.value=e),label:"Key","lazy-rules":"",rules:[e=>e&&e.length>0||"Please type something"]},null,8,["modelValue","rules"]),t("div",null,[l(n,{label:"Submit",type:"submit",color:"primary"}),l(n,{label:"Reset",type:"reset",color:"primary",flat:"",class:"q-ml-sm"})])]),_:1})])):(d(),m("div",P,"You not initialize core. Initialize it first."))]))}};export{N as default};