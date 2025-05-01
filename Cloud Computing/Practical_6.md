To create a Docker image for your Portfolio project in Google Cloud Shell, follow these steps:

---

### 🧰 Step 1: Open Your Project Folder

From your screenshot, it looks like the folder is named Portfolio.

   
cd Portfolio
   

Make sure your project contains the main entry file (like index.html, app.js, etc.).

---

### 📄 Step 2: Create a Dockerfile

Use this command to create a Dockerfile:

   
nano Dockerfile
   

For a simple static HTML site (e.g., TailwindCSS portfolio), paste this:

   Dockerfile
# Use Nginx to serve static files
FROM nginx:alpine
COPY . /usr/share/nginx/html
EXPOSE 80
   

If your project is a Node.js app, use:

   Dockerfile
# Use Node.js base image
FROM node:18
WORKDIR /app
COPY . .
RUN npm install
EXPOSE 3000
CMD ["npm", "start"]
   

Press Ctrl + O, Enter, then Ctrl + X to save and exit.

---

### 🔨 Step 3: Build Docker Image

Replace portfolio-image with any name you want:

   
docker build -t portfolio-image .
   

Wait for the build to complete.

---

### ▶️ Step 4: Run the Docker Image

If it’s a static site:

   
docker run -d -p 8080:80 portfolio-image
   

If it’s a Node.js app:

   
docker run -d -p 3000:3000 portfolio-image
   

---

### 🌐 Step 5: Access the App

If you’re using Cloud Shell, use the “Web Preview” button (🔗 icon at top right) → Port 8080 or 3000, depending on your app.

---

