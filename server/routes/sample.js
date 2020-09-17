class SampleRoute {
  constructor(server) {
    console.log("SampleRoute \t Registering SampleRoute...");
    this.registerRoutes(server);
    console.log("SampleRoute \t Route Registered to server");
  }

  get(req, res, next) {
    res.status(200).json("Get: Welcome to test API");
    next();
  }

  post(req, res, next) {
    res.status(200).json("Post: " + req.body.value);
    next();
  }

  put(req, res, next) {
    res.status(200).json("Put: " + req.body.value);
    next();
  }

  patch(req, res, next) {
    res.status(200).json("Patch: " + req.body.value);
    next();
  }

  delete(req, res, next) {
    res.status(200).json("Delete: " + req.body.value);
    next();
  }

  registerRoutes(server) {
    server.get("", this.get);
    server.post("", this.post);
    server.put("", this.put);
    server.patch("", this.patch);
    server.delete("", this.delete);
  }
}

module.exports = SampleRoute;
