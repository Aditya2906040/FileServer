# Phase 2: User Authentication & Access Control

## 🎯 Goal
Secure the file sharing system with user-based authentication, access control, and detailed logging.

---

## ✅ Features

- **User Registration & Login System**  
  New users can register with a username and password. Returning users must log in before accessing the system.  

- **Per-User Storage Directories**  
  Each authenticated user is assigned a dedicated storage directory. Files uploaded/downloaded are isolated to that user’s space.  

- **Authentication Checks**  
  Server verifies user credentials before allowing file operations. Unauthorized users cannot access commands.  

- **Access Restrictions**  
  Users can only list, upload, and download their own files. No cross-user access is permitted.  

- **Access Logs**  
  Every action is logged with:  
  - Username  
  - Command issued  
  - Target filename (if applicable)  
  - Timestamp  
  - Status (Success, Invalid Command, Error)  

---

## ⚙️ Updated Command Flow

- `REGISTER <username> <password>` – Create a new account  
- `LOGIN <username> <password>` – Authenticate an existing account  
- `LIST` – List files in the user’s directory  
- `UPLOAD <filename>` – Upload file to the user’s directory  
- `DOWNLOAD <filename>` – Download file from the user’s directory  
- `LOGOUT` – End user session gracefully  

---

## 📝 Logging Strategy

- **On Login** – Log username and login status (success/failure)  
- **On Command Execution** – Log each command along with status (success/invalid/error)  
- **On Logout/Disconnect** – Log session termination  

Logs are stored in `logs/` with a consistent format for easy parsing.  

---

## 📂 Project Structure (Extended)

```
LANShare++/
│
├── src/
│   ├── server.cpp
│   ├── client.cpp
│   ├── command_parser.cpp
│   ├── auth.cpp
│   └── logger.cpp
│
├── include/
│   ├── protocol.hpp
│   ├── utilities.hpp
│   ├── auth.hpp
│   └── logger.hpp
│
├── users/               # Per-user directories
├── logs/                # Access logs
├── Makefile
└── README.md
```

---

## 📌 Notes

- Authentication happens **before** any file transfer commands.  
- Logs serve both as a **security audit trail** and for **debugging invalid commands**.  
- User directories ensure **data isolation** and **privacy**.  

---

⚡ This phase builds security and accountability on top of Phase 1’s core functionality.  
