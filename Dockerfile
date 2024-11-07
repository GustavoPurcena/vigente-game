FROM node:18-slim

WORKDIR /app

# Copy package files
COPY package*.json ./

# Install dependencies
RUN npm install

# Copy project files
COPY . .

# Build SCSS
RUN npm run build

EXPOSE 3000

CMD [ "npm", "start" ]