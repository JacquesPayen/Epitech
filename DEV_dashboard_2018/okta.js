const okta = require('@okta/okta-sdk-nodejs')

const client = new okta.Client({
    orgUrl: 'https://dev-364450.oktapreview.com',
    token: '00hh0kYUoYwECZvU-eDehrkOJgEIpW4svsCy81cuhn',
})

const middleware = async (req, res, next) => {
  if (req.userinfo) {
    try {
      req.user = await client.getUser(req.userinfo.sub)
    } catch (error) {
      console.log(error)
    }
  }

  next()
}

module.exports = { client, middleware }
