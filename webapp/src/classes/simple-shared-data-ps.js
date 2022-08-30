/* eslint-disable no-prototype-builtins */
class SimpleSharedDataPlatformService {
    setString(groupName, key, value) {
        var json = this.create(groupName);
        json[key] = value;
        this.save(json, groupName);
    }

    setInteger(groupName, key, value) {
        var json = this.create(groupName);
        json[key] = value;
        this.save(json, groupName);
    }

    setLong(groupName, key, value) {
        var json = this.create(groupName);
        json[key] = value;
        this.save(json, groupName);
    }

    setBool(groupName, key, value) {
        var json = this.create(groupName);
        json[key] = value;
        this.save(json, groupName);
    }

    setFloat(groupName, key, value) {
        var json = this.create(groupName);
        json[key] = value;
        this.save(json, groupName);
    }

    setDouble(groupName, key, value) {
        var json = this.create(groupName);
        json[key] = value;
        this.save(json, groupName);
    }

    getString(groupName, key) {
        return this.getStringWithDefaultValue(groupName, key, "");
    }

    getInteger(groupName, key) {
        return this.getIntegerWithDefaultValue(groupName, key, 0);
    }

    getLong(groupName, key) {
        return this.getLongWithDefaultValue(groupName, key, 0);
    }

    getBool(groupName, key) {
        return this.getBoolWithDefaultValue(groupName, key, false);
    }

    getFloat(groupName, key) {
        return this.getFloatWithDefaultValue(groupName, key, 0);
    }

    getDouble(groupName, key) {
        return this.getDoubleWithDefaultValue(groupName, key, 0);
    }

    getStringWithDefaultValue(groupName, key, defaultValue) {
        var json = this.create(groupName);

        if (json.hasOwnProperty(key)) {
            if (json[key]) {
                return String(json[key]);
            }
        }

        return defaultValue;
    }

    getIntegerWithDefaultValue(groupName, key, defaultValue) {
        var json = this.create(groupName);

        if (json.hasOwnProperty(key)) {
            if (json[key]) {
                try {
                    return parseInt(json[key]);
                } catch (error) {
                    // ignore
                }
            }
        }

        return defaultValue;
    }

    getLongWithDefaultValue(groupName, key, defaultValue) {
        var json = this.create(groupName);

        if (json.hasOwnProperty(key)) {
            if (json[key]) {
                try {
                    return parseInt(json[key]);
                } catch (error) {
                    // ignore
                }
            }
        }

        return defaultValue;
    }

    getBoolWithDefaultValue(groupName, key, defaultValue) {
        var json = this.create(groupName);

        if (json.hasOwnProperty(key)) {
            if (json[key]) {
                return Boolean(json[key]);
            }
        }

        return defaultValue;
    }

    getFloatWithDefaultValue(groupName, key, defaultValue) {
        var json = this.create(groupName);

        if (json.hasOwnProperty(key)) {
            if (json[key]) {
                try {
                    return parseFloat(json[key]);
                } catch (error) {
                    // ignore
                }
            }
        }

        return defaultValue;
    }

    getDoubleWithDefaultValue(groupName, key, defaultValue) {
        var json = this.create(groupName);

        if (json.hasOwnProperty(key)) {
            if (json[key]) {
                try {
                    return parseFloat(json[key]);
                } catch (error) {
                    // ignore
                }
            }
        }

        return defaultValue;
    }

    has(groupName, key) {
        var json = this.create(groupName);

        if (json.hasOwnProperty(key)) {
            return true;
        }

        return false;
    }

    remove(groupName, key) {
        var json = this.create(groupName);

        if (json.hasOwnProperty(key)) {
            json.erase(key);
        }

        this.save(json, groupName);
    }

    clear(groupName) {
        window.localStorage.removeItem("ntv-shared-data-" + groupName);
    }

    save(json, groupName) {
        window.localStorage.setItem(
            "ntv-shared-data-" + groupName,
            JSON.stringify(json)
        );
    }

    create(groupName) {
        var data = window.localStorage.getItem("ntv-shared-data-" + groupName);

        if (data) {
            return JSON.parse(data);
        } else {
            return {};
        }
    }
}

export default SimpleSharedDataPlatformService;
