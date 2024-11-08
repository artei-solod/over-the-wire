<p align='center'>
  <img src='assets/s1.svg' width='180' alt='Hacker spider'>
</p>

СЕВА ТЫ КАК ТАМ ЕПТА
# Over-the-wire [![GitHub license](https://img.shields.io/github/license/vaguue/over-the-wire?style=flat)](https://github.com/vaguue/over-the-wire/blob/main/LICENSE) [![npm](https://img.shields.io/npm/v/over-the-wire)](https://www.npmjs.com/package/over-the-wire) ![Development Status](https://img.shields.io/badge/status-in_development-orange)

*The project is currently under active development.*

## Overview
`over-the-wire` is a Node.js packet manipulation library supporting:
- Packet crafting and parsing
- Capturing network traffic and sending packets in all formats
- Parsing and serializing pcap and pcapng file formats
- Creating custom non-TCP/UDP socket instances

## System Requirements
- Libpcap/WinPcap/Npcap library installed (if Wireshark is installed on your system, you are good to go)
- Node.js version 16.10.0 or higher recommended
- C++ compiler, if there are no prebuilt bindings for your system

## Installation

```bash
npm install over-the-wire --save
```

## Getting started

```javascript
const fs = require('fs');
const { Pcap, Packet } = require('over-the-wire');

const dev = new Pcap.LiveDevice({
  iface: 'en0',
  direction: 'inout',
  filter: 'src port 443',
});

// Get info about interface
console.log('[*] Interface: ', dev.iface);

// Save captured packets to a pcapng file
const dump = Pcap.createWriteStream({ format: 'pcapng' });
dump.pipe(fs.createWriteStream('dump.pcapng'));

dev.on('data', pkt => {
  if (pkt.layers.IPv4) {
    console.log(`[*] ${pkt.layers.IPv4.src} -> ${pkt.layers.IPv4.dst}`);
  }
  dump.write(pkt);
});

// Create and inject a packet
const pkt = new Packet({ iface: dev.iface })
                .Ethernet()
                .IPv4({ dst: '192.168.1.1' })
                .ICMP();
dev.write(pkt);
```

## Documentation

[Here :)](https://vaguue.github.io/over-the-wire)

## Questions or Suggestions
Feel free to open any issue in the Issues section of this repository. Currently, there are no restrictions on the format.
