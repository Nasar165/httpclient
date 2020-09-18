const express = require("express");
const registerRoutes = require("./routes/routes");
const startServer = require("./core/server");
const registerMiddleware = require("./middleware/core");

require("dotenv").config();

console.log("Section \t Message\n");
console.log("Server: \t Begin Server setup...");
const server = express();

if (registerMiddleware(server) > 0)
  throw new Error(" Failed to register middleware");

if (registerRoutes(server) > 0) throw new Error(" Failed to register routes");

if (startServer(server) > 0) throw new Error(" Failed to start server");
