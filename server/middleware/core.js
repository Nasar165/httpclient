const cors = require("cors");
const bodyParser = require("body-parser");

function registerMiddleware(server) {
  if (!server) return 1;

  console.log("Middleware: \t Trying to register middleware...");
  server.use(cors());
  server.use(bodyParser.json());
  server.use(bodyParser.urlencoded({ extended: true }));

  console.log("Middleware: \t Middleware registered!");
  return 0;
}

module.exports = registerMiddleware;
