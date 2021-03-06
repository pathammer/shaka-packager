// Copyright 2014 Google Inc. All rights reserved.
//
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file or at
// https://developers.google.com/open-source/licenses/bsd

#ifndef MEDIA_FILE_UDP_FILE_H_
#define MEDIA_FILE_UDP_FILE_H_

#include <stdint.h>

#include <string>

#include "packager/base/compiler_specific.h"
#include "packager/media/file/file.h"

namespace shaka {
namespace media {

/// Implements UdpFile, which receives UDP unicast and multicast streams.
class UdpFile : public File {
 public:
  /// @param file_name C string containing the address of the stream to receive.
  ///        It should be of the form "<ip_address>:<port>".
  explicit UdpFile(const char* address_and_port);

  /// @name File implementation overrides.
  /// @{
  bool Close() override;
  int64_t Read(void* buffer, uint64_t length) override;
  int64_t Write(const void* buffer, uint64_t length) override;
  int64_t Size() override;
  bool Flush() override;
  bool Seek(uint64_t position) override;
  bool Tell(uint64_t* position) override;
  /// @}

 protected:
  ~UdpFile() override;

  bool Open() override;

 private:
  int socket_;

  DISALLOW_COPY_AND_ASSIGN(UdpFile);
};

}  // namespace media
}  // namespace shaka

#endif  // MEDIA_FILE_UDP_FILE_H_
