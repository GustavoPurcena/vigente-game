const express = require('express');
const path = require('path');
const app = express();
const port = process.env.PORT || 3000;

// Serve static files from the 'public' directory
app.use(express.static(path.join(__dirname, 'public')));

app.get('/', (req, res) => {
  res.sendFile(path.join(__dirname, 'views', 'index.html'));
});

// Route for card pages
app.get('/:cardName', (req, res) => {
  const cardName = req.params.cardName;
  const cardPath = path.join(__dirname, 'views', `${cardName}.html`);
  
  res.sendFile(cardPath, err => {
    if (err) {
      res.status(404).send('Card not found');
    }
  });
});

app.listen(port, () => {
  console.log(`Server running on http://localhost:${port}`);
});
