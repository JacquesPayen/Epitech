const express = require('express')
const { startCase } = require('lodash')
const bodyParser = require('body-parser');
const models = require('../models')
const router = express.Router()
router.use(bodyParser.urlencoded({ extended: false }));

function temperature(ville, callback) {
    var weather = require('weather-js');
    weather.find({ search: ville, degreeType: 'C' }, function (err, result) {
        var sting;
        if (err) console.log(err);
        else if (result.length != 0) {
            var temperature = JSON.stringify(result[0].current.temperature);
            sting = 'Temperature of ' + ville + ' : ' + temperature + ' C.';
        }
        callback(sting);
    });
}

function wind(ville, callback) {
    var weather = require('weather-js');
    weather.find({ search: ville, degreeType: 'C' }, function (err, result) {
        var sting;
        if (err) console.log(err);
        else if (result.length != 0) {
            var wind = JSON.stringify(result[0].current.windspeed);
            sting = 'Wind speed of ' + ville + ' : ' + wind;
        }
        callback(sting);
    });
}

function humidity(ville, callback) {
    var weather = require('weather-js');
    weather.find({ search: ville, degreeType: 'C' }, function (err, result) {
        var sting;
        if (err) console.log(err);
        else if (result.length != 0) {
            var humidity = JSON.stringify(result[0].current.humidity);
            sting = 'Humidity of ' + ville + ' : ' + humidity + ' %';
        }
        callback(sting);
    });
}

function view(video, callback) {
    var fetchVideoInfo = require('youtube-info');
    fetchVideoInfo(video, function (err, videoInfo) {
        var sting;
        if (err) throw new Error(err);
        var name = JSON.stringify(videoInfo.title);
        var view = JSON.stringify(videoInfo.views);
        if (name != undefined)
            sting = name + ' has ' + view + ' views.';
        callback(sting);
    });
}

function like(video, callback) {
    var fetchVideoInfo = require('youtube-info');
    fetchVideoInfo(video, function (err, videoInfo) {
        var sting;
        if (err) throw new Error(err);
        var name = JSON.stringify(videoInfo.title);
        var like = JSON.stringify(videoInfo.likeCount);
        if (name != undefined)
            sting = name + ' has ' + like + ' likes.';
        callback(sting);
    });
}

function dislike(video, callback) {
    var fetchVideoInfo = require('youtube-info');
    fetchVideoInfo(video, function (err, videoInfo) {
        var sting;
        if (err) throw new Error(err);
        var name = JSON.stringify(videoInfo.title);
        var dislike = JSON.stringify(videoInfo.dislikeCount);
        if (name != undefined)
            sting = name + ' has ' + dislike + ' dislikes.';
        callback(sting);
    });
}

router.get('/', function (req, res, next) {
  const { profile } = req.user
  const descriptionList = Object.keys(profile).sort()
    .map(key => ({
      term: startCase(key),
      details: profile[key],
    }))
        .filter(({ details }) => details)
    var yt;
    var we;
    models.Userinfo.findOne({
        where: {
            username: req.user.profile.email
        }
    }).then(myuser => {
        console.log(myuser)
        if (!myuser) {
            we = false
            yt = false
            models.Userinfo.create({
                username: req.user.profile.email,
                youtube: false,
                meteo: false,
                wlist: 'Temperature;Combloux, FR;',
            })
        }
        else {
            we = myuser.meteo
            yt = myuser.youtube
        }
        if (!myuser) {
            var result = [];
            res.render('dashboard', {
                title: 'Dashboard',
                descriptionList,
                user: req.user,
                yt,
                we,
                result
            })
        }
        else {
            array = myuser.wlist
            var bite = array.split(";");
            var y = 0
            var sting;
            var result = [];
            while (y <= bite.length) {
                getInformation(bite[y], bite[y + 1], function (returnValue) {
                    sting = returnValue;
                    result.push(sting);
                    if (result.length >= (bite.length / 2) - 1) {
                        res.render('dashboard', {
                            title: 'Dashboard',
                            descriptionList,
                            user: req.user,
                            yt,
                            we,
                            result
                        })
                    }
                });
                y = y + 2
            }
        }
        });
  
})

function getInformation(widget, arg, callback) {
    var sting;
    if (widget == "Temperature") {
        temperature(arg, function (returnValue) {
            sting = returnValue;
            callback(sting);
        });
    }
    else if (widget == "Humidity") {
        humidity(arg, function (returnValue) {
            sting = returnValue;
            callback(sting);
        });
    }
    else if (widget == "Wind") {
        wind(arg, function (returnValue) {
            sting = returnValue;
            callback(sting);
        });
    }
    else if (widget == "View") {
        view(arg, function (returnValue) {
            sting = returnValue;
            callback(sting);
        });
    }
    else if (widget == "Like") {
        like(arg, function (returnValue) {
            sting = returnValue;
            callback(sting);
        });
    }
    else if (widget == "Dislike") {
        dislike(arg, function (returnValue) {
            sting = returnValue;
            callback(sting);
        });
    }
}

    router.post('/', async (req, res, next) => {
        var arg = req.body.text;
        var widget = req.body.widget;
        var name = req.user.profile.email;
        var test = JSON.stringify(arg);
        if (widget == "Activate Weather Service") {
            models.Userinfo.findOne({
                where: {
                    username: req.user.profile.email
                }
            }).then(myuser => {
                if (myuser) {
                    myuser.updateAttributes({
                        meteo: true,
                    })
                }
            });
            }
            else if (widget == "Activate Youtube Service") {
            models.Userinfo.findOne({
                where: {
                    username: req.user.profile.email
                }
            }).then(myuser => {
                if (myuser) {
                    myuser.updateAttributes({
                        youtube: true,
                    })
                }
            });
            }
        else {
            models.Userinfo.findOne({
                where: {
                    username: req.user.profile.email
                }
            }).then(myuser => {
                if (myuser) {
                    var newwidget = myuser.wlist + widget + ";" + arg + ";"
                    myuser.updateAttributes({
                        wlist: newwidget
                    })
                }
            });
            }
            console.log(name);
            console.log(widget);
        console.log(arg);
        res.redirect('/dashboard');
    })

    module.exports = router