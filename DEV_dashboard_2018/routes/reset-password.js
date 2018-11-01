const okta = require('@okta/okta-sdk-nodejs')
const express = require('express')

const router = express.Router()

const client = new okta.Client({
    orgUrl: 'https://dev-364450.oktapreview.com',
    token: '002zhIhuu67u_ewA-qNY2xoFbhsEFNYNSrKvrigGx9',
})

const title = 'Password Recovery'

router.get('/', (req, res, next) => {
  res.render('reset-password', { title })
})

router.post('/', async (req, res, next) => {
  try {
    const user = await client.getUser(req.body.email)

    await user.resetPassword()
    res.render('reset-password', { title, success: true })
  } catch (error) {
    res.render('reset-password', {
      title,
      error: 'Could not find an account with that email address',
      body: req.body,
    })
  }
})

module.exports = router
