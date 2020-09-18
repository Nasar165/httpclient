const SampleRoute = require("./sample");

function registerRoutes(server) {
  if (!server) return 1;
  console.log("Routes: \t Trying to register Routes...");
  new SampleRoute(server);
  console.log("Routes: \t Routes registered!");
  return 0;
}

module.exports = registerRoutes;
