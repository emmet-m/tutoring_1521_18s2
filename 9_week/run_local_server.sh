#!/bin/bash

echo "Running server on \"localhost:8080\""
echo "Type text to respond! CTRL+D to finish."
nc -l -p 8080
