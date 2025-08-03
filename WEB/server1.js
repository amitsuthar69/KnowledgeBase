import express from "express";
const app = express();

app.use(express.json());

const authMiddleware = (req, res, next) => {
  const token = req.header("auth-token");
  if (token && token == "some-token") {
    next();
  } else {
    return res.status(401).json({ message: "Unauthorized Access!" });
  }
};

const users = [];

app.get("/", (req, res) => {
  res.json({ message: "Hello" });
});

// app.use(authMiddleware); // global use

// route level use
app.get("/protected", authMiddleware, (req, res) => {
  res.json({ message: "Protected Route." });
});

app.get("/users", (req, res) => {
  return res.status(200).json(users);
});

app.get("/user/:id", (req, res) => {
  const user = users.find((u) => u.id == parseInt(req.params.id));
  if (!user) {
    return res.status(404).json({ message: "User not found!" });
  }
  return res.status(200).json(user);
});

app.post("/users", (req, res) => {
  const { name, age } = req.body;
  if (!name || !age) {
    return res.status(400).json({ message: "Name and age are required" });
  }
  let newUser = { id: users.length + 1, name, age };
  users.push(newUser);
  return res
    .status(201)
    .json({ message: "User Created Successfully!", result: newUser });
});

app.listen("3000", () => {
  console.log("INFO: server listening on: http://localhost:3000");
});
