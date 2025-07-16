# 📄 Phase 1 Specifications - SockIt FileServer

---

## 🚀 Project Overview

**SockIt FileServer** is a terminal-based file sharing system built in C++. It allows clients to connect to a central server over TCP sockets to perform file operations like:

- Listing files
- Uploading files
- Downloading files

The core architecture relies on blocking BSD sockets and a simple text-based protocol to manage communication between client and server.

---

## 🧠 Phase 1 Goals

- [x] Setup TCP socket server and client using BSD sockets
- [x] Implement CLI-driven menu on server side for user selection
- [x] Support LIST command for displaying available server files
- [x] Implement basic UPLOAD and DOWNLOAD operations via client requests
- [x] Ensure communication follows a line-terminated command protocol
- [x] Create modular C++ headers for clear file separation
- [x] Add platform support for both Windows and Linux

---

## 🧱 Architecture

```text
        +----------------+                +----------------+
        |                |  TCP Socket    |                |
        |  C++ Client    |<-------------->|  C++ Server     |
        |  (file_client) |   Commands     |  (file_server)  |
        +----------------+                +----------------+
```

### Components

| Component         | Role                                            |
| ----------------- | ----------------------------------------------- |
| `file_server.cpp` | Main server handling sockets and routing        |
| `file_client.cpp` | Client to interact with server via protocol     |
| `file_ops.hpp`    | Handles file I/O like upload/download           |
| `menu.hpp`        | Server-side CLI interface (getch-style)         |
| `utils.hpp`       | Utility functions (e.g., progress bars)         |
| `protocol.hpp`    | Encodes/decodes text commands for communication |

---

## 📦 Command Protocol

All messages are line-terminated (`\n`), and commands follow a simple text format:

- `LIST` — Request list of server files
- `UPLOAD filename` — Upload a file to server
- `DOWNLOAD filename` — Download a file from server
- `EXIT` — Disconnect client

The end of the list is marked with: `EOF\n`

---

## 🗂️ Folder Structure

```text
/sockit/
├── server/
│   ├── basicServer.cpp        # Entry point with menu loop
│   ├── menu.hpp               # Menu and input handling
│   ├── file_server.cpp        # Core socket logic
│   ├── server.hpp             # Server socket setup
│   ├── client_handler.hpp     # Handles command dispatch
│   ├── file_ops.hpp           # File handling functions
│   └── server_files/          # Directory for hosted files
├── client/
│   └── file_client.cpp        # Command-line client
├── shared/
│   ├── utils.hpp              # Shared utilities
│   └── protocol.hpp           # Text-based command format
├── logs/
│   └── server_log.txt         # Optional logs
├── docs/
│   ├── README.md              # General documentation
│   └── phase1_spec.md         # (This file)
```

---

## 💻 Development Environment

| Tool       | Details                   |
| ---------- | ------------------------- |
| OS         | Ubuntu 22.04 / Windows 10 |
| Language   | C++17                     |
| Compiler   | g++ / MSVC                |
| Socket API | BSD sockets / Winsock     |

---

## ✅ Phase 1 Outcome

- Successfully created an end-to-end working file server-client system
- Transferred files using a simple, readable protocol
- Practiced modular C++ design with proper folder structure
- Code ready for future enhancements (multithreading, GUI, auth, etc.)

---

## 📌 Next Steps (for Phase 2)

- Add support for concurrent clients using threads or `select()`
- Implement client-side file selector or argument parsing
- Add authentication and access control
- Integrate Python/Qt GUI client (optional)
- Logging and error reporting improvements

---

> Prepared with ❤️ by Aditya Raman
