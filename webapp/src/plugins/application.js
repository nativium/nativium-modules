export default {
    install: (app) => {
        app.provide("Application", {
            reset() {
                // ignore
            },
        });
    },
};
