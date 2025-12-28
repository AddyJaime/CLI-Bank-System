# CLI-Bank-System

A small  **Command-Line Interface (CLI) Bank System** written in C++ and built with `clang++`.

## 🚀 Project overview

This project is a simple starting point for a CLI-based bank system. It will include features such as:

- **Create accounts**
- **Deposit / Withdraw / Transfer** funds
- **List accounts** and basic balance checks
- Simple persistence (to be added)

The codebase is intentionally minimal — it's meant for learning and iterating on C++ design, data structures, and CLI UX.

---

## 🛠️ Build & run (clang++)

Quick compile (single file / prototype):

```bash
# create bin/ first (if it doesn't exist)
mkdir -p bin
# build
clang++ -std=c++17 -O2 -Wall -Wextra src/main.cpp -I include -o bin/cli_bank
# run
./bin/cli_bank
```

If you add more `.cpp` files under `src/` you can build them together:

```bash
clang++ -std=c++17 -O2 -Wall -Wextra src/*.cpp -I include -o bin/cli_bank
```

> Tip: Use `-g` while developing to include debug symbols, and consider `clang-tidy` / `clang-format` for style and linting.

---

## ✍️ Contribution

Open an issue or submit a PR with improvements, tests, or features. Keep things small and focused.

---

**Happy hacking!**
