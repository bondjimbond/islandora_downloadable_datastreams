# Islandora Downloadable Datastreams
Creates a block on objects of select CModels that allows users to download un-exposed datastreams. 
Currently displays for large image, newspaper issue, book, audio, and video.
Large Image datastream may be configured. Book and Newspaper Issue download PDFs if they exist. Audio uses the PROXY_MP3 datastream. Video uses MP4. Future development will make these configurable.

## Requirements
* [Islandora](https://github.com/Islandora/islandora)

## Installation
Same as any Drupal module.

## Configuration
On the config page: 
- Enter the name of the datastream you wish to use for large image downloads.
- Enter the label to use for the Download block.
- Select the content models for which you want the block to be available.

Note: While all content models are listed on this screen, only six are actually usable:
- Large Image
- Book
- Newspaper Issue
- Audio
- Video
- PDF (displays only when a viewer is being used)

## Customization
The block creates a simple HTML link, in a div with the CSS class "downloadlink". Apply CSS as you like.

## Maintainer

[Brandon Weigel](https://github.com/bondjimbond)
