function startServer(server) {
  if (!server) return 1;
  console.log("Express: \t Starting Server...");
  const listener = server.listen(process.env.PORT || 3000, () => {
    const port = listener.address().port;
    console.log("Express: \t Server is listening on PORT: " + port);
  });
  return 0;
}

module.exports = startServer;
