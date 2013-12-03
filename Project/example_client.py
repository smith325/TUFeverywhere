
import logging, sys

import tuf.client.updater

# need to reference json so PyInstaller can find json to use with TUF
import json

def update():
  # Set the local repository directory containing the metadata files.
  tuf.conf.repository_directory = '.'


  repository_mirrors = {'mirror1': {'url_prefix': 'http://localhost:8001',
                                    'metadata_path': 'metadata',
                                    'targets_path': 'targets',
                                    'confined_target_dirs': ['']}}

  # Create the Upater object using the updater name 'tuf-example'
  # and the repository mirrors defined above.
  updater = tuf.client.updater.Updater('tuf-example', repository_mirrors)

  # Set the local destination directory to save the target files.
  destination_directory = './targets'

  # Refresh the repository's top-level roles, store the target information for
  # all the targets tracked, and determine which of these targets have been
  # updated.
  updater.refresh()
  all_targets = updater.all_targets()
  updated_targets = updater.updated_targets(all_targets, destination_directory)

  # Download each of these updated targets and save them locally.
  for target in updated_targets:
    try:
      updater.download_target(target, destination_directory)
    except tuf.DownloadError, e:
      pass

  # Remove any files from the destination directory that are no longer being
  # tracked.
  updater.remove_obsolete_targets(destination_directory)

def loader():
  execfile("DynamicUpdate.py")

def main():
  try:
    update()
  except:
    raise
  loader()

if __name__ == "__main__":
    main()
