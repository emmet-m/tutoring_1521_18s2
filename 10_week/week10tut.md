# Week 10 tutorial 

Where to from COMP1521 first, then

## Network stack

1. Application
2. Transport
3. Network
4. Link
5. Physical

### Application

Things that work on top of sockets
FTP, HTTP, SSH, SMTP
Each of these definte a *protocol*

**An aside: URLs**

Take the URL https://www.cse.unsw.edu.au:443/cs9999/18s2/showMarks?item=quiz2

What is the:
* protocol
* host
* port
* path
* query

### TCP and UDP (Transport)

Sends a message to a specific process across a network

Need an address and port:
* Address identifies *which machine* to find
* Port identifies *which process on the machine* to talk to

TCP is:
* "Transmission Control Protocol"
* An ordered stream of bytes
* Error checked
* Acknowledged upon arrival

**WHEN WOULD I USE THIS?**

UDP is:
* "User Datagram Protocol"
* No order
* No error checking (corruption!)
* Could mysteriously go missing, and never be known

**WHEN WOULD I USE THIS?**

### IP (Internet Protocol, Routers)

Sends a message to a specific machine across a network

Needs an address!

IPV4:
* 4 bytes of information
* Structured like 255.0.10.123

IPV6:
* 16 bytes of information
* Looks like 2001:0db8:85a3:0000:0000:8a2e:0370:7334 (groups of octets)
* Impossibly huge address space

Each machine gets a unique IP address (not really in reality, but assume it works like that...)

**How to I obtain such an IP address?**

A process called DHCP (not covered in this course) - Dynamic Host Configuration Protocol

**How can I translate a URL to an actual IP address?**

DNS lookup!
* You have a local DNS server, this contacts global DNS servers
* e.g. First the root server is contacted, giving the matching TLD server
* Your local DNS server then looks up the correct TLD server for a hostname
* Then contacts the hostname IP...
* so on

Perform DNS lookup on "www.cse.unsw.edu.au" and "google.com"

DNS Cache poisoning

### Link Layer (Switches, Routers)

Which physically connected do I go to next?

Need a *MAC Address*

Looks like 00:0d:83:b1:c0:8e

### Physical Layer

Just bits on a wire!

## Exercises

Look up some IP addresses with host:

www.cse.unsw.edu.au
moss.stanford.edu
kora01.orchestra.cse.unsw.edu.au
kora02.orchestra.cse.unsw.edu.au
kora03.orchestra.cse.unsw.edu.au

Look at /etc/services and identify which network services use which port numbers

21
22
25
80
101
443

Show off DNS lookup?

Debug a buggy mips program!
