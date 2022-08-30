class SimpleLoggerPlatformService {
    v(message) {
        console.log("[V] " + message);
    }

    d(message) {
        console.log("[D] " + message);
    }

    i(message) {
        console.log("[I] " + message);
    }

    w(message) {
        console.log("[W] " + message);
    }

    e(message) {
        console.log("[E] " + message);
    }

    setGroup(group) {
        console.log("[GROUP] " + group);
    }
}

export default SimpleLoggerPlatformService;
