# Phase 1 – Core File Sharing System

## 🎯 Objective

Build the backbone of the system — a working client–server file transfer application using TCP sockets.

---

## 🚀 Features

### 1. TCP Socket Server & Client (One-to-One)

- A single client connects to the server at a time.
- Graceful client disconnection is supported.

### 2. Command-Based Protocol

Supported commands:

- `LIST` → List available files on the server.
- `UPLOAD <filename>` → Send a file from client to server.
- `DOWNLOAD <filename>` → Fetch a file from server to client.
- `EXIT` → Disconnect from server.

### 3. File Transfer Mechanism

- Files are transferred in **chunks** (e.g., 1024 bytes).
- Buffered transfer ensures stability and efficiency for large files.

### 4. Basic Server File Management

- Server maintains a **shared directory** for storing files.
- Uploaded files from clients are saved in this directory.

### 5. Stability Features

- Handles invalid commands gracefully with error messages.
- Ensures proper **connection closure** after transfers or exit.

---

## 🛠️ Tech Stack

- **Language:** C++
- **Networking:** TCP Sockets (POSIX/WinSock depending on OS)
- **File I/O:** Standard C++ file streams (ifstream, ofstream)
- **Protocol:** Custom text-based command protocol

---

## 📌 Workflow (High-Level)

1. **Client connects** to server via TCP socket.
2. Server sends a **welcome message** and awaits commands.
3. Client sends one of the supported commands:
   - LIST → Server responds with list of available files.
   - UPLOAD → Client sends file in chunks, server stores it.
   - DOWNLOAD → Server sends requested file in chunks.
   - EXIT → Connection gracefully closed.
4. On invalid command, server responds with an error message.

---

## ✅ Deliverables for Phase 1

- Functional **server and client** programs.
- Command-based file sharing between them.
- Stable handling of file transfer and disconnection.

---

## 🔜 Next Phase (Future Roadmap)

- User authentication system.
- Per-user directories.
- Access logs for auditing.
- Encryption for secure file transfer.
