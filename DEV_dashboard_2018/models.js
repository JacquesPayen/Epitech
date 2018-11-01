const Sequelize = require("sequelize");

const helpers = require("./helpers");


const db = helpers.getDB();
const Userinfo = db.define("post", {
    username: { type: Sequelize.STRING },
    youtube: { type: Sequelize.BOOLEAN, defaultValue: false },
    meteo: { type: Sequelize.BOOLEAN, defaultValue: false },
    wlist: { type: Sequelize.STRING, defaultValue: 'Temperature;Combloux, FR;' },
});

db.sync();


module.exports = { Userinfo };