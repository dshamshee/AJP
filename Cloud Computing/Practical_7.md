Here's a complete guide to create a VM in Mumbai region (asia-south1-a) and deploy your containerized HTML application without errors:

---

### **Step 1: Create a Properly Configured VM Instance**

1. **Go to Google Cloud Console** → Compute Engine → VM instances
2. **Click "Create Instance"**
3. **Configure with these settings**:
   - **Name**: `html-app-vm`
   - **Region**: `asia-south1` (Mumbai)
   - **Zone**: `asia-south1-a`
   - **Machine Type**: `e2-small` (2 vCPU, 2GB RAM)
   - **Boot Disk**: Ubuntu 22.04 LTS (30GB standard persistent disk)
   - **Firewall**: Check both "Allow HTTP traffic" and "Allow HTTPS traffic"
4. **Under "Identity and API access"**:
   - Select "Allow full access to all Cloud APIs"
5. **Click "Create"**

---

### **Step 2: Connect to Your VM**

1. Wait for VM to start (green checkmark appears)
2. Click **"SSH"** button next to your instance

---

### **Step 3: Set Up Docker on the VM**

Run these commands in the SSH terminal:

 
# Update packages
sudo apt-get update

# Install Docker
sudo apt-get install -y docker.io

# Start and enable Docker
sudo systemctl start docker
sudo systemctl enable docker

# Add your user to docker group
sudo usermod -aG docker $USER
newgrp docker
  

---

### **Step 4: Create Your HTML Application**

 
# Create project directory
mkdir ~/html-app && cd ~/html-app

# Create HTML file
cat > index.html <<'EOF'
<!DOCTYPE html>
<html>
<head>
    <title>My Mumbai HTML App</title>
    <style>
        body { font-family: Arial, sans-serif; text-align: center; margin-top: 50px; }
        h1 { color: #EA4335; }
    </style>
</head>
<body>
    <h1>Hello from Mumbai Cloud VM!</h1>
    <p>Served via Docker container</p>
</body>
</html>
EOF

# Create Nginx config
mkdir nginx-conf
cat > nginx-conf/default.conf <<'EOF'
server {
    listen       80;
    server_name  localhost;
    location / {
        root   /usr/share/nginx/html;
        index  index.html index.htm;
    }
}
EOF
  

---

### **Step 5: Create Dockerfile**

 
cat > Dockerfile <<'EOF'
FROM nginx:alpine
COPY index.html /usr/share/nginx/html/
COPY nginx-conf/default.conf /etc/nginx/conf.d/default.conf
EXPOSE 80
CMD ["nginx", "-g", "daemon off;"]
EOF
  

---

### **Step 6: Build and Run Container**

 
# Build image
docker build -t html-app .

# Run container
docker run -d -p 80:80 --name my-html-app html-app
  

---

### **Step 7: Configure Firewall (if not auto-configured)**

 
# Create firewall rule (if needed)
gcloud compute firewall-rules create allow-http \
    --allow tcp:80 \
    --direction INGRESS \
    --target-tags http-server \
    --region asia-south1

# Add tag to VM
gcloud compute instances add-tags html-app-vm \
    --tags http-server \
    --zone asia-south1-a
  

---

### **Step 8: Access Your Application**

1. **Get your VM's external IP**:
    
   gcloud compute instances describe html-app-vm \
       --zone asia-south1-a \
       --format='value(networkInterfaces[0].accessConfigs[0].natIP)'
     

2. **Open in browser**:
     
   http://[YOUR_VM_IP]
     

---

### **Verification Commands**

Check container status:
 
docker ps
  

View logs:
 
docker logs my-html-app
  

Test locally:
 
curl http://localhost
  

---

### **Troubleshooting Tips**

1. If you get **port 80 in use**:
    
   sudo netstat -tulnp | grep :80
   sudo kill <PID>
     

2. If container exits immediately:
    
   docker logs my-html-app
     

3. To update your app:
    
   docker stop my-html-app
   docker rm my-html-app
   docker build -t html-app .
   docker run -d -p 80:80 --name my-html-app html-app
     

This configuration ensures your Mumbai-based VM has:
- Proper API access scopes
- Correct firewall rules
- Sufficient resources
- Automatic HTTP port access
- Persistent Docker service

Let me know if you encounter any issues during this process!