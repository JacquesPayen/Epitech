const express = require('express')
const { startCase } = require('lodash')

const router = express.Router()
function temperature(ville) {
    var weather = require('./weather-js');
    weather.find({ search: ville, degreeType: 'C' }, function (err, result) {
        if (err) console.log(err);
        var temperature = JSON.stringify(result[0].current.temperature);
        console.log(temperature);
        return (temperature);
    });
}
module.exports = router
