import http from "http";

const users = [];
const middlewares = [];

const use = (middleware) => middlewares.push(middleware);

const withMiddleware = (req, res, middlewares, idx = 0) => {
  if (idx == middlewares.length) return;
  const middleware = middlewares[idx];
  middleware(req, res, function next() {
    withMiddleware(req, res, middlewares, idx + 1);
  });
};

use((req, _res, next) => {
  console.log(`Request URL: ${req.url}`);
  next(); // pass control
});

const server = http.createServer((req, res) => {
  withMiddleware(req, res, middlewares);

  const { method, url } = req;

  if (method === "GET" && url.startsWith("/")) {
    res.writeHead(200, { "content-type": "application/json" });
    res.end(JSON.stringify({ message: "Hello" }));
  } else if (method === "POST" && url.startsWith("/users")) {
    let data = "";
    req.on("data", (chunk) => {
      data += chunk.toString();
    });

    req.on("end", () => {
      try {
        let user = JSON.parse(data);

        if (!user.name || !user.age) {
          res.writeHead(400, { "content-type": "application/json" });
          req.end(JSON.stringify({ message: "Name & Age are required" }));
          return;
        }
        user.id = users.length + 1;
        users.push(user);

        res.writeHead(201, { "Content-Type": "application/json" });
        res.end(JSON.stringify(user));
      } catch (error) {
        res.writeHead(400, { "Content-Type": "application/json" });
        res.end(JSON.stringify({ error: "Invalid JSON" }));
      }
    });
  } else {
    res.writeHead(404, { "Content-Type": "application/json" });
    res.end(JSON.stringify({ error: "Route not found" }));
  }
});

server.listen(3000, () => {
  console.log("INFO: server listening on: http://localhost:3000");
});
