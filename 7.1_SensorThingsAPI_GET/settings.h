#pragma once

const char protocol[] = "http";
const char host[] = "192.168.0.105";
const uint16_t port = 49154;
const char path[] = "/v1.0";

auto domain = String(host) + ":" + port + "/FROST-Server";
auto base_url = String(protocol) + "://" + domain + path;
