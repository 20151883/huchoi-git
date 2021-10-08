const express = require("express");

const router = express.Router();
router.get("/test.html", (req, res, next) => {
    res.send("this is router.js");
})
module.exports = router;