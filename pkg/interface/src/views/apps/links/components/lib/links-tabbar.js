import React, { Component } from 'react';
import { Link } from 'react-router-dom';
import { makeRoutePath } from '../../../../../logic/lib/util';

export class LinksTabBar extends Component {
  render() {
    const props = this.props;

    let setColor = '';

    if (props.location.pathname.includes('/settings')) {
      setColor = 'black white-d';
    } else {
      setColor = 'gray3';
    }

    const hidePopoutIcon = (props.popout)
    ? 'dn-m dn-l dn-xl'
    : 'dib-m dib-l dib-xl';

    return (
      <div className="dib flex-shrink-0 flex-grow-1">
        <div className={'dib pt2 f9 pl6 pr6 lh-solid'}>
          <Link
            className={'no-underline ' + setColor}
            to={makeRoutePath(props.resourcePath, props.popout) + '/settings'}
          >
            Settings
          </Link>
        </div>
        <a href={makeRoutePath(props.resourcePath, true, props.page)}
          target="_blank"
          rel="noopener noreferrer"
          className="dib fr pt2 pr1"
        >
          <img
            className={'flex-shrink-0 pr3 dn ' + hidePopoutIcon}
            src="/~link/img/popout.png"
            height="16"
            width="16"
          />
        </a>
      </div>
    );
  }
}

export default LinksTabBar;
