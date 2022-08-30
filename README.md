# Nativium - Modules

<p align="center">
    <a href="https://github.com/nativium/nativium-modules" target="_blank" rel="noopener noreferrer">
        <img src="extras/images/logo.png" alt="Nativium Modules" style="max-width: 200px;" width="200px">
    </a>
</p>

<br>

<p align="center">
    <a href="https://github.com/nativium/nativium-modules/actions/workflows/linux.yml"><img src="https://github.com/nativium/nativium-modules/actions/workflows/linux.yml/badge.svg"></a>
    <a href="https://github.com/nativium/nativium-modules/actions/workflows/macos.yml"><img src="https://github.com/nativium/nativium-modules/actions/workflows/macos.yml/badge.svg"></a>
    <a href="https://github.com/nativium/nativium-modules/actions/workflows/windows.yml"><img src="https://github.com/nativium/nativium-modules/actions/workflows/windows.yml/badge.svg"></a>
    <a href="https://github.com/nativium/nativium-modules/actions/workflows/ios.yml"><img src="https://github.com/nativium/nativium-modules/actions/workflows/ios.yml/badge.svg"></a>
    <a href="https://github.com/nativium/nativium-modules/actions/workflows/android.yml"><img src="https://github.com/nativium/nativium-modules/actions/workflows/android.yml/badge.svg"></a>
    <a href="https://github.com/nativium/nativium-modules/actions/workflows/wasm.yml"><img src="https://github.com/nativium/nativium-modules/actions/workflows/wasm.yml/badge.svg"></a>
</p>

<br>

<p align="center">This is a group of Nativium modules ready to use in production.</p>

<br>

# General

The modules are ready to use with [Nativium](https://github.com/nativium/nativium) project. Visit oficial website:

https://github.com/nativium/nativium

# Build for Linux

Execute the following commands to build for Linux:

```
git clone https://github.com/nativium/nativium.git nativium
cd nativium
python nativium.py custom install --path=../custom
python nativium.py target linux setup
python nativium.py target linux build
python nativium.py target linux run
```

# Build for macOS

Execute the following commands to build for macOS:

```
git clone https://github.com/nativium/nativium.git nativium
cd nativium
python nativium.py custom install --path=../custom
python nativium.py target macos setup
python nativium.py target macos build
python nativium.py target macos run
```

# Build for Windows

Execute the following commands to build for Windows:

```
git clone https://github.com/nativium/nativium.git nativium
cd nativium
python nativium.py custom install --path=../custom
python nativium.py target windows setup
python nativium.py target windows build
python nativium.py target windows run
```

Obs: On Windows the terminal needs to be opened as `administrator`, otherwise the `symlinks` will not be created.

# Build for iOS

Execute the following commands to build for iOS:

```
git clone https://github.com/nativium/nativium.git nativium
cd nativium
python nativium.py custom install --path=../custom
python nativium.py target ios setup
python nativium.py target ios build
python nativium.py target ios package --no-framework
python nativium.py target ios dist generate
python nativium.py app ios-pods
```

Open the project for Xcode:

```
open apps/ios/runner/Runner.xcworkspace
```

# Build for Android

Execute the following commands to build for Android:

```
git clone https://github.com/nativium/nativium.git nativium
cd nativium
python nativium.py custom install --path=../custom
python nativium.py target android setup
python nativium.py target android build
python nativium.py target android package
python nativium.py target android dist generate
```

Open the project for Android Studio:

```
apps/android/runner
```

# Build for WASM

Execute the following commands to build for Web Assembly (WASM):

```
git clone https://github.com/nativium/nativium.git nativium
cd nativium
python nativium.py custom install --path=../custom
python nativium.py target wasm setup
python nativium.py target wasm build
python nativium.py target wasm serve
```
