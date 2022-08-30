import { createRouter, createWebHistory } from "vue-router";
import MainView from "../views/MainView.vue";

const router = createRouter({
    history: createWebHistory(import.meta.env.BASE_URL),
    routes: [
        {
            path: "/",
            name: "home",
            component: MainView,
        },
        {
            path: "/about",
            name: "about",
            // route level code-splitting
            // this generates a separate chunk (About.[hash].js) for this route
            // which is lazy-loaded when the route is visited.
            component: () => import("../views/AboutView.vue"),
        },
        {
            path: "/page/initialize",
            name: "page/initialize",
            component: () => import("../views/pages/PageInitializeView.vue"),
        },

        {
            path: "/page/customer",
            name: "page/customer",
            component: () => import("../views/pages/PageCustomerView.vue"),
        },
        {
            path: "/page/login",
            name: "page/login",
            component: () => import("../views/pages/PageLoginView.vue"),
        },
        {
            path: "/page/shared-data",
            name: "page/shared-data",
            component: () => import("../views/pages/PageSharedDataView.vue"),
        },
        {
            path: "/page/file",
            name: "page/file",
            component: () => import("../views/pages/PageFileView.vue"),
        },
        {
            path: "/page/todo-list",
            name: "page/todo-list",
            component: () => import("../views/pages/PageTodoListView.vue"),
        },
    ],
});

export default router;
